open Lib;

module Log = (val logger("FileSystem"));

module D = {
  let data = Dir.App.data(~appIdentifier=C.Strings.appName);
  let meta = Fp.At.(Fp.dot / ".metadata");
};

let save = (path: Fp.t(Fp.relative), contents) => {
  let path = Fp.join(D.data, path);
  Log.debug("Writing: " ++ Fp.toDebugString(path));
  let dir = Fp.dirName(path);
  let _ = Fs.mkDirP(dir);
  Fs.writeTextExn(path, contents);
};

let load = (path: Fp.t(Fp.relative)) => {
  let path = Fp.join(D.data, path);
  Fs.readTextExn(path);
};
