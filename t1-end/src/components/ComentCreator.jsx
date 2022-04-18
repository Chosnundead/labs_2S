import React, { useState } from "react";
import github from "../images/github.png";
import { MyButton } from "./UI/button/MyButton";
import { MyInput } from "./UI/input/MyInput";

export const ComentCreator = ({ addComentFromComentCreator, ...props }) => {
  const [isImageDivActive, setIsImageDivActive] = useState(false);
  const [coment, setComent] = useState({
    name: "",
    body: "",
    password: "",
    avatar: github,
    eMail: "",
  });
  return (
    <form>
      <MyInput
        placeHolder="Имя"
        value={coment.name}
        onChange={(event) => {
          setComent({ ...coment, name: event.target.value });
        }}
      />
      <br />
      <MyInput
        placeHolder="Коментарий"
        value={coment.body}
        onChange={(event) => {
          setComent({ ...coment, body: event.target.value });
        }}
      />
      <br />
      <MyInput
        placeHolder="E-mail*"
        value={coment.eMail}
        onChange={(event) => {
          setComent({ ...coment, eMail: event.target.value });
        }}
      />
      <br />
      <MyInput
        placeHolder="Секретное слово"
        value={coment.password}
        onChange={(event) => {
          setComent({ ...coment, password: event.target.value });
        }}
      />
      <br />
      {!isImageDivActive ? (
        <MyButton
          style={{ width: "200px" }}
          onClick={(event) => {
            event.preventDefault();
            setIsImageDivActive(true);
          }}
        >
          Choose a image
        </MyButton>
      ) : (
        false
      )}
      {isImageDivActive ? (
        <div
          style={{
            display: "grid",
            gridTemplateColumns: "1fr 1fr 1fr 1fr",
            maxWidth: "100px",
            border: "2px solid darkred",
          }}
        >
          <img
            src={github}
            width="21px"
            height="21px"
            onClick={(event) => {
              setComent({ ...coment, avatar: github });
              setIsImageDivActive(false);
            }}
          />
        </div>
      ) : (
        false
      )}
      <br />
      <MyButton
        onClick={(event) => {
          event.preventDefault();
          if (coment.name != "" && coment.body != "" && coment.password != "") {
            addComentFromComentCreator(coment);
            setComent({
              name: "",
              body: "",
              password: "",
              avatar: github,
              eMail: "",
            });
          } else alert("Заполните поля формы корректно!");
        }}
      >
        Push
      </MyButton>
    </form>
  );
};
