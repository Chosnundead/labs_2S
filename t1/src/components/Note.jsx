import React from "react";

const Note = (props) => {
  let color = "yellow";
  if (props.size >= 8) {
    color = "red";
  }
  return (
    <div style={{ backgroundColor: color }}>
      <h2>
        {props.title}({props.date})
      </h2>
      <p>{props.text}</p>
    </div>
  );
};
export default Note;
