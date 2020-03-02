open Lib;
open Revery;
open Revery.Math;
open Revery.UI;
open Revery.UI.Components;

let textStyle =
  Style.[
    color(C.Color.text),
    fontFamily(C.Font.firaSansRegular),
    fontSize(16.0),
  ];

module TitleBar = {
  let style =
    Style.[
      backgroundColor(C.Color.bgDarkStrong),
      height(22),
      justifyContent(`Center),
      alignItems(`Center),
      paddingHorizontal(120),
      paddingTop(4),
      overflow(`Hidden),
      borderBottom(~color=C.Color.borderInverse, ~width=1),
    ];
  let textStyle =
    Style.[
      color(C.Color.textDim),
      fontFamily(C.Font.firaSansRegular),
      fontSize(12.0),
    ];
  let make = () => {
    <View style> <Text style=textStyle text="Chess Tea" /> </View>;
  };
};

module ContentContainer = {
  let style =
    Style.[
      backgroundColor(C.Color.bgDarkStrong),
      alignItems(`Stretch),
      flexDirection(`Row),
      flexGrow(1),
    ];

  let innerStyle =
    Style.[
      alignItems(`Stretch),
      flexDirection(`Row),
      flexGrow(1),
    ];

  let%component make = () => {
    let%hook (route, setRoute) = Router.useRoute();
    let view =
      switch (route) {
      | Main => <MainView />
      | ChessBoard => <ChessBoard />
      | Playground => <MainView />
      };

    <View style>
      <LeftNav />
      <View style=innerStyle>
        {view}
      </View>
    </View>
  };
};

module PowerLine = {
  let style =
    Style.[
      backgroundColor(C.Color.bgCyan),
      height(22),
      justifyContent(`Center),
      alignItems(`Center),
      paddingHorizontal(12),
      paddingTop(2),
      overflow(`Hidden),
      borderTop(~color=C.Color.borderInverse, ~width=1),
    ];
  let textStyle =
    Style.[
      color(C.Color.text),
      fontFamily(C.Font.firaSansRegular),
      fontSize(14.0),
    ];
  let make = () => {
    <View style> <Text style=textStyle text="" /> </View>;
  };
};

let rootContainer =
  Style.[
    backgroundColor(C.Color.bgDarkStrong),
    position(`Absolute),
    alignItems(`Stretch),
    flexDirection(`Column),
    bottom(0),
    top(0),
    left(0),
    right(0),
    border(~color=C.Color.borderWeak, ~width=1),
  ];

let%component make = () => {
  let%hook (state, dispatch) = AppState.useState();
  <View style=rootContainer>
    <TitleBar />
    <ContentContainer />
    <PowerLine />
  </View>;
};
