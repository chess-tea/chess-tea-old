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

module ObjectBrowser = {
  let style =
    Style.
      [
        backgroundColor(C.Color.bgDark),
        width(220),
        padding(8),
        overflow(`Hidden),
      ];
      // borderRight(~color=C.Color.borderInverse, ~width=1),
  let make = () => {
    <View style> <Text style=textStyle text="Objects" /> </View>;
  };
};

module Workspace = {
  let style =
    Style.[
      backgroundColor(C.Color.bgDarkWeak),
      flexGrow(1),
      padding(8),
      overflow(`Hidden),
    ];
  let make = () => {
    <View style> <Text style=textStyle text="Workspace" /> </View>;
  };
};

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

module MainContent = {
  let style =
    Style.[
      backgroundColor(C.Color.bgDarkStrong),
      alignItems(`Stretch),
      flexDirection(`Row),
      flexGrow(1),
    ];
  let make = () => {
    <View style> <LeftNav /> <ObjectBrowser /> <Workspace /> </View>;
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
    <MainContent />
    <PowerLine />
  </View>;
};
