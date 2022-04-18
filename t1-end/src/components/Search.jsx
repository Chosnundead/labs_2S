import React, { useState } from "react";
import { MyInput } from "./UI/input/MyInput";

export const Search = ({ _setTypeOfSortFromSearch, ...props }) => {
  const [typeOfSort, setTypeOfSort] = useState({
    search: "",
    select: "isNew",
    isStandartOrder: "true",
  });
  return (
    <div>
      <MyInput
        style={{ marginRight: "20px" }}
        placeHolder="Поиск..."
        onChange={(event) => {
          setTypeOfSort({ ...typeOfSort, search: event.target.value });
          _setTypeOfSortFromSearch({
            ...typeOfSort,
            search: event.target.value,
          });
        }}
      />
      <select
        style={{ marginLeft: "20px", marginRight: "20px" }}
        onChange={(event) => {
          setTypeOfSort({ ...typeOfSort, select: event.target.value });
          _setTypeOfSortFromSearch({
            ...typeOfSort,
            select: event.target.value,
          });
        }}
      >
        <option disabled={true}>Сортировка</option>
        <option value="isNew">По новинкам</option>
        <option value="name">По имени</option>
        <option value="price">По цене</option>
        <option value="discount">По скидкам</option>
      </select>
      <text style={{ marginLeft: "20px", marginRight: "10px" }}>Порядок:</text>
      <input
        type="radio"
        name="order"
        style={{ display: "inline", width: "fit-content" }}
        value={"true"}
        defaultChecked
        onClick={(event) => {
          setTypeOfSort({ ...typeOfSort, isStandartOrder: event.target.value });
          _setTypeOfSortFromSearch({
            ...typeOfSort,
            isStandartOrder: event.target.value,
          });
        }}
      />
      <text style={{ marginRight: "10px" }}>По убыванию</text>
      <input
        type="radio"
        name="order"
        style={{ display: "inline", width: "fit-content" }}
        value={"false"}
        onClick={(event) => {
          setTypeOfSort({ ...typeOfSort, isStandartOrder: event.target.value });
          _setTypeOfSortFromSearch({
            ...typeOfSort,
            isStandartOrder: event.target.value,
          });
        }}
      />
      <text>По возрастанию</text>
    </div>
  );
};
