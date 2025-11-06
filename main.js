const { app, BrowserWindow } = require('electron/main')
const path = require('node:path')

const createWindow = () => {
  const win = new BrowserWindow({
    width: 600,
    height: 600,
    webPreferences: {
      preload: path.join(__dirname, 'preload.js')
    }
  })
  win.loadFile('index.html')
  win.setMenu(null) // Remove menu bar
  win.resizable = false;
}

app.whenReady().then(() => {
  createWindow()

  app.on('activate', ()=> {
    if (BrowserWindow.getAllWindows().length === 0) {
      createWindow()
    }
  })
})

// User not on macOS, iOS, etc... and is closing the app
app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit()
  }
})