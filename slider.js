var slider = document.getElementById("password-length-slider");
var output = document.getElementById("password-length");
output.innerHTML = slider.value;

slider.oninput = function() {
    output.innerHTML = this.value;
}
