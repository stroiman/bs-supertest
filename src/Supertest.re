module Response = {
  type t;

  [@bs.get] external getBody : t => Js.t('a) = "body";
  [@bs.get] external getBodyJson : t => Js.Json.t = "body";
};

module Error = {
  type t;
};
type t;
type errorCallback = (Js.null(Error.t), Response.t) => unit;
[@bs.module] external request : Express.App.t => t = "supertest";
[@bs.module "supertest"] external agent : Express.App.t => t = "";
[@bs.send.pipe : t] external get : string => t = "get";
[@bs.send.pipe : t] external post : string => t = "post";
[@bs.send.pipe : t] external send : (Js.t('a)) => t = "send";
[@bs.send.pipe : t] external sendString : string => t = "send";
[@bs.send.pipe : t] external expectStatus : int => t = "expect";
[@bs.send.pipe : t] external end_ : errorCallback => unit = "end";
let end_ = (cb, req) => {
  let cb = (err, x) =>
    switch (Js.Null.to_opt(err)) {
      | None => cb(Js.Result.Ok(x))
      | Some(y) => cb(Js.Result.Error(y))
      };
  req |> end_(cb)
  };

