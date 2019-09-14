let useDidMount = f => React.useEffect1(f, [||]);

let useWillUnmount = f => React.useEffect1(() => Some(() => f()), [||]);

let useDidUpdate = (f, conditions) => {
  let didMoutRef = React.useRef(false);
  React.useEffect1(
    () =>
      React.Ref.(
        switch (didMoutRef->current) {
        | false =>
          didMoutRef->setCurrent(true);
          None;
        | true => f()
        }
      ),
    conditions,
  );
};
  let useClock = () => {
    let (date, setDate) = React.useState(() => Js.Date.now());
    let tick = () => {
      setDate(_ => Js.Date.now());
    };
    React.useEffect(() => {
      let ticker = Js.Global.setInterval(() => tick(), 1000);
      Some(() => Js.Global.clearInterval(ticker));
    });
    date;
  };