require("ansicolor").nice;

var Globals = {
  options: {
    serialPortName: "/dev/cu.usbmodem142301",
    serialPortRate: 9600,
    webSocketPortNumber: 8081,
    enable: true,
    serialConnectRetryIntervalInSeconds:5,
    listSerialPorts: false,
  },
  socket:0,
  serialPortReadBytes:0,
  serialPortWriteBytes:0,
  serialPortStatus:"closed",
  statusbarLines:["Please wait..."],
  intervals: {
    statusBarTextInterval: null
  },
  statusBarTextInterval_ms: 500,
  wsConnections:[],
};

const log = require("log-with-statusbar")({
  ololog_configure: {
    // time: { yes: true, print: x => x.toLocaleString().bright.cyan + " " },
    locate: false,
    tag: true
  },
  initialStatusTextArray: Globals.statusbarLines,
  minVerbosity: 1, //Minimum verbosity level
  verbosity: 1, //Default verbosity level
  enableStatusBar: true
});

var exports = (module.exports = {
  Globals: Globals,
  // options: options,
  log: log
});
