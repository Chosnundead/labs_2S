import React, { useState } from "react";
import { MyButton } from "./UI/button/MyButton";

export const NewNote = ({
  deleteNotesFromNewNote,
  changeNotesFromNewNote,
  note,
  ...props
}) => {
  const [value, setValue] = useState(note.body);
  return (
    <div>
      <h2>
        {note.title}{" "}
        <MyButton
          onClick={(event) => {
            deleteNotesFromNewNote(note.id);
          }}
        >
          Delete
        </MyButton>
      </h2>

      <textarea
        value={value}
        onChange={(event) => {
          setValue(event.target.value);
          changeNotesFromNewNote(note.id, event.target.value);
        }}
      ></textarea>
    </div>
  );
};
