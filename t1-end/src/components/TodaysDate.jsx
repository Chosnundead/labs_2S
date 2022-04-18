import React from "react";
import { useState } from "react";

function _timeAsString(one, two) {
  let time = new Date();
  let time2 = new Date(time + " GMT" + one);
  if (time2.getHours() > 12 && two == 12) {
    return `${
      time2.getHours() - 12
    }:${time2.getMinutes()}:${time2.getSeconds()} PM`;
  } else if (two == 12) {
    return `${time2.getHours()}:${time2.getMinutes()}:${time2.getSeconds()} AM`;
  } else {
    return `${time2.getHours()}:${time2.getMinutes()}:${time2.getSeconds()}`;
  }
}

const TodaysDate = (props) => {
  const [date, setDate] = useState(
    _timeAsString(props.time.timeZone, props.time.format)
  );
  setInterval(() =>
    setDate(_timeAsString(props.time.timeZone, props.time.format), 100)
  );
  return <h2>{date}</h2>;
};

export default TodaysDate;
