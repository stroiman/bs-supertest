# bs-supertest
Bucklescript wrapper for supertest (node.js express test helper)

## Supertest

Supertest (the original node package) is a nice tool for testing express
applications. You can test all your express bindings without having to start an
http server and issuing http requests. And it also implements an "agent", i.e.
you can simulate multiple requests from the same agent, having cookies being
handles. Thus you can test authentication flow, etc.

[Find the original Supertest here](https://github.com/visionmedia/supertest)

## This wrapper

This wrapper is build to be used with `bs-express`.

Only a few functions from everything from this package has had bucklescript
bindings created, I add them as I need them in my real project.

For the same reason, I have not published an npm package yet - I don't want to
reserve the package name at this point in time.

The easiest way of installing is to install the npm package directly from git:
```
npm install --save-dev git+https://github.com/PeteProgrammer/bs-supertest.git
```
Remember to add the package name to `bsconfig.json` too.

Everything is released under the MIT license, and pull requests are most welcome
if they are made available under the MIT license as well.

This is a simple example, using
[Respect](https://github.com/PeteProgrammer/respect)

```
    describe("A valid opbject is posted", [
      it("Returns 200", (_, don) => {
        let app = Express.App.make();
        let obj = {
          "email": "asdasd",
          "emailRepeat": "asdasd"
        };
        Application.initialize(app);
        Supertest.request(app)
          |> Supertest.post("/api/auth/register")
          |> Supertest.send(obj)
          |> Supertest.expectStatus(200)
          |> Supertest.end_(r => {
            switch r {
              | Ok(_) => don()
              | Error(_) => don(~err="Error",())
            }
            });
      })
```

