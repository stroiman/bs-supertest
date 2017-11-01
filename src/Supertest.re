  module Error = {
    type t;
  };
  type t;
  type errorCallback('a) = (Js.null(Error.t), Js.t('a)) => unit;
  [@bs.module] external request : Express.App.t => t = "supertest";
  [@bs.send.pipe : t] external get : string => t = "get";
  [@bs.send.pipe : t] external post : string => t = "post";
  [@bs.send.pipe : t] external send : (Js.t('a)) => t = "send";
  [@bs.send.pipe : t] external sendString : string => t = "send";
  [@bs.send.pipe : t] external expectStatus : int => t = "expect";
  [@bs.send.pipe : t] external end_ : errorCallback('a) => unit = "end";
  let end_ = (cb, req) => {
    let cb = (err, x) =>
      switch (Js.Null.to_opt(err)) {
      | None => cb(Js.Result.Ok(x))
      | Some(y) => cb(Js.Result.Error(y))
      };
    req |> end_(cb)
  };

