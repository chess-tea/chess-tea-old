/**
 * This is the core module that should be opened in every file, it contains
 * commonly used modules and types.
 */;

module Caml = {
  module Array = Array;
  module Char = Char;
  module List = List;
  module Option = Option;
  module String = String;
};

module Option = Bread.Option;

module Infix = {
  let (>>|) = Option.map;
  let (>>=) = Option.flatMap;
  let (>>?) = Option.get(false);
  let (@>) = (@@);
  let (@.) = (f, g, x) => g(f(x));
};

include Infix;

let logger = Timber.Log.withNamespace;
