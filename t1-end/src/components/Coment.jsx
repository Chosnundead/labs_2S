import React, { useState } from "react";
import { MyButton } from "./UI/button/MyButton";
import { MyInput } from "./UI/input/MyInput";

export const Coment = ({
  coment,
  changeBodyFromComent,
  deleteComentFromComent,
  ...props
}) => {
  const [body, setBody] = useState(coment.body);
  const [isDeleteInput, setIsDeleteInput] = useState(false);
  const [isInfo, setIsInfo] = useState(false);
  return (
    <div>
      <h2>
        <img src={coment.avatar} width="21px" height="21px" /> {coment.name}
      </h2>
      <textarea
        style={{ width: "400px", height: "100px", resize: "none" }}
        value={body}
        onChange={(event) => {
          setBody(event.target.value);
          changeBodyFromComent({ ...coment, body: event.target.value });
        }}
      ></textarea>
      <p>
        {isDeleteInput ? (
          <MyInput
            style={{ marginRight: "20px" }}
            placeHolder="Секретное слово"
            onChange={(event) => {
              if (event.target.value === coment.password) {
                deleteComentFromComent(coment.id);
              }
            }}
          />
        ) : (
          <MyButton
            style={{ marginRight: "20px" }}
            onClick={(event) => {
              setIsDeleteInput(true);
            }}
          >
            Удалить
          </MyButton>
        )}
        {isInfo ? (
          <text style={{ marginLeft: "20px" }}>
            Последние изменения: {coment.id.getHours()}:
            {coment.id.getMinutes() <= 9
              ? "0" + coment.id.getMinutes()
              : coment.id.getMinutes()}{" "}
            {coment.id.getDate()}.{coment.id.getMonth() + 1}.
            {coment.id.getFullYear()}
          </text>
        ) : (
          <MyButton
            style={{ marginLeft: "20px" }}
            onClick={(event) => {
              setIsInfo(true);
            }}
          >
            Информация
          </MyButton>
        )}
      </p>
    </div>
  );
};
