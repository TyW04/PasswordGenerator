// Addon to use C++ functions within JS
// The code within this file is mostly copied from Electron native C++
// addon documentation. https://www.electronjs.org/docs/latest/tutorial/native-code-and-electron

#include <napi.h>
#include <string>
#include "../include/passwordgen.h"

class PasswordGenAddon : public Napi::ObjectWrap<PasswordGenAddon> {
    public:
        // Static method defines class for JS
        static Napi::Object Init(Napi::Env env, Napi::Object exports) {
            Napi::Function func = DefineClass(env, "PasswordGenAddon", {
                InstanceMethod("generatePassword", &PasswordGenAddon::generatePassword)
            });

            // Create a persistent reference to the constructor
            Napi::FunctionReference* constructor  = new Napi::FunctionReference();
            *constructor = Napi::Persistent(func);
            env.SetInstanceData(constructor);

            // Set the constructor on the exports object
            exports.Set("PasswordGenAddon", func);
            return exports;
        }
        
        // Constructor
        // TODO: Need to pass in a struct for the generatePassword function
        PasswordGenAddon(const Napi::CallbackInfo& info)
            : Napi::ObjectWrap<PasswordGenAddon>(info) {}

    private:

        // Method that will be exposed to JS
        Napi::Value GeneratePassword(const Napi::CallbackInfo &info) {
            Napi::env env = info.Env();

            // Validate arguments (expecting one string)
            if (info.Length() < 1 || !info[0].IsString()) {
                Napi::TypeError::New(env, "Expected string argument").ThrowsAsJavaScriptException();
                return env.Null();
            }

            // Convert JS string to C++ string
            std::string input = info[0].As<Napi::String>();

            // Call our C++ function
            std::string password = PasswordGen::generatePassword(/*Struct required*/);

            // Convert C++ string back to JS string and return
            return Napi::String::New(env, password);
        }
};

// Initialize the addon
Napi::Object Init(Napi::Env env, Napi::Object exports) {
    return PasswordGenAddon::Init(env, exports);
}

// Register the initialization function
NODE_API_MODULE(passwordgen_addon, Init)