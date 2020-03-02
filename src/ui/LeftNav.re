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

module Icon = {
  let viewStyle =
    Style.[
      height(50),
      justifyContent(`Center),
      alignItems(`Center),
      paddingTop(12),
    ];

  let viewActiveStyle =
    viewStyle
    @ Style.[
        // PaddingLeft + BorderLeft + MarginLeft = 0
        marginLeft(-8),
        paddingLeft(6),
        borderLeft(~color=C.Color.text, ~width=2),
      ];

  let textStyle =
    Style.[
      color(C.Color.textDim),
      fontFamily(C.Font.firaCodeBold),
      fontSize(36.0),
    ];

  let textHoverStyle = textStyle @ Style.[color(C.Color.text)];

  // TODO: Add remaining controls, for example accept chlild element.
  let%component make = (~active=false, ~onClick=_ => (), ~text, ()) => {
    let%hook (hover, setHover) = Hooks.state(false);
    let style = if (active) {viewActiveStyle} else {viewStyle};

    let textStyle =
      if (active || hover) {
        textHoverStyle;
      } else {
        textStyle;
      };

    let onMouseOver = _ => setHover(_ => true);
    let onMouseOut = _ => setHover(_ => false);
    <Clickable onClick>
      <View style onMouseOver onMouseOut> <Text style=textStyle text /> </View>
    </Clickable>;
  };
};

module TopGutter = {
  let style =
    Style.[flexDirection(`Column), alignItems(`Stretch), flexGrow(1)];

  let%component make = () => {
    let%hook (route, setRoute) = Router.useRoute();

    <View style>
      <Icon text="M" active={route == Main} onClick={_ => setRoute(Main)} />
      <Icon
        text="C"
        active={route == ChessBoard}
        onClick={_ => setRoute(ChessBoard)}
      />
      <Icon
        text="P"
        active={route == Playground}
        onClick={_ => setRoute(Playground)}
      />
    </View>;
  };
};

module BottomGutter = {
  let style = Style.[flexDirection(`Column), alignItems(`Stretch)];

  let make = () => {
    <View style> <Icon text="X" /> <Icon text="Y" /> </View>;
  };
};

let style =
  Style.[
    backgroundColor(C.Color.bgDarkStrong),
    width(70),
    padding(8),
    overflow(`Hidden),
    flexDirection(`Column),
    alignItems(`Stretch),
  ];

let make = () => {
  <View style> <TopGutter /> <BottomGutter /> </View>;
};
