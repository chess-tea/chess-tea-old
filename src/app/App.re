open Lib;
open Revery;

module Log = (val logger("App"));

let start = () => {
  let init = app => {
    Timber.App.enable();
    Timber.App.setLevel(Timber.Level.debug);
    Timber.App.setNamespaceFilter("");

    Log.info("Start: Creating window");
    let window =
      Revery.App.createWindow(
        ~createOptions=
          Revery.WindowCreateOptions.create(
            ~width=1280,
            ~height=800,
            ~vsync=Revery.Vsync.Immediate,
            ~titlebarStyle=Revery.WindowStyles.Transparent,
            (),
          ),
        app,
        C.Strings.appName,
      );
    Revery.Window.setBackgroundColor(window, C.Color.bgDarkStrong);
    Log.info("End: creating window");

    let rootElement = <RootElement />;
    let update = Revery.UI.start(window, rootElement);
    let _ = update;

    FileSystem.save(FileSystem.D.meta, [Time.toString(Time.now())]);
  };

  let _ = Revery.App.start(init);
  ();
};

let run = () => start();
