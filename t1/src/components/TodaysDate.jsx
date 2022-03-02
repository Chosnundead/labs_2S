import React from "react";
import { useState } from "react";

function _timeAsString(props) {
  let time = new Date();
  time = new Date(time.toLocaleString() + " GMT" + props[0]);
  if (time.getHours() > 12 && props[1] == 12) {
    return `${
      time.getHours() - 12
    }:${time.getMinutes()}:${time.getSeconds()} PM`;
  } else if (props[1] == 12) {
    return `${time.getHours()}:${time.getMinutes()}:${time.getSeconds()} AM`;
  } else {
    return `${time.getHours()}:${time.getMinutes()}:${time.getSeconds()}`;
  }
}

const TodaysDate = (props) => {
  const [date, setDate] = useState(
    _timeAsString([props.time.timeZone, props.time.format])
  );
  setInterval(() =>
    setDate(_timeAsString([props.time.timeZone, props.time.format]), 100)
  );
  return <h2>{date}</h2>;
};

export default TodaysDate;
