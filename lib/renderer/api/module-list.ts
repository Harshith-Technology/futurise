// Renderer side modules, please sort alphabetically.
export const rendererModuleList: ElectronInternal.ModuleEntry[] = [
  { name: 'contextBridge', loader: () => require('./context-bridge') },
  { name: 'crashReporter', loader: () => require('./crash-reporter') },
  { name: 'ipcRenderer', loader: () => require('./ipc-renderer') },
  { name: 'nativeImage', loader: () => require('./native-image') },
  { name: 'webFrame', loader: () => require('./web-frame') }
];

if (BUILDFLAG(ENABLE_DESKTOP_CAPTURER)) {
  rendererModuleList.push({
    name: 'desktopCapturer',
    loader: () => require('@electron/internal/renderer/api/desktop-capturer')
  });
}
