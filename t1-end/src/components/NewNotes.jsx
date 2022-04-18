import React, { useState } from "react";
import { NewNote } from "./NewNote";
import { MyInput } from "./UI/input/MyInput";
import { MyButton } from "./UI/button/MyButton";

export const NewNotes = ({
  deleteNotesFromNewNote,
  changeNotesFromNewNote,
  setNotesFromNewNotes,
  notes,
  ...props
}) => {
  const [note, setNote] = useState({ title: "", body: "" });

  return (
    <div>
      <form>
        <p>
          Заголовок:{" "}
          <MyInput
            onChange={(event) => {
              setNote({ ...note, title: event.target.value });
            }}
            value={note.title}
          />
        </p>
        <p>
          Описание:{" "}
          <MyInput
            onChange={(event) => {
              setNote({ ...note, body: event.target.value });
            }}
            value={note.body}
          />
        </p>
        <p>
          <MyButton
            onClick={(event) => {
              event.preventDefault();
              setNotesFromNewNotes(note.title, note.body);
              setNote({ title: "", body: "" });
            }}
          >
            Добавить
          </MyButton>
        </p>
      </form>

      {notes.map((item, index) => {
        return (
          <NewNote
            note={item}
            changeNotesFromNewNote={changeNotesFromNewNote}
            deleteNotesFromNewNote={deleteNotesFromNewNote}
          />
        );
      })}
    </div>
  );
};
