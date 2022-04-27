import React, { useState } from "react";
import "../styles/Product.css";
import PropTypes from "prop-types";

export const Product = ({ product, ...props }) => {
  const [numberOfImage, setNumberOfImage] = useState(0);
  return (
    <div {...props} className="product-main">
      <div className="product-left">
        <p className="product-left-ablosute">
          {product.isNew ? (
            <text className="product-left-ablosute-new">Новинка</text>
          ) : (
            false
          )}
          <text className="product-left-ablosute-discount">
            {product.discount}%
          </text>
        </p>
        <img
          className="product-left-image"
          width="300px"
          height="300px"
          src={product.images[numberOfImage]}
          onClick={(event) => {
            if (numberOfImage + 1 === product.images.length) {
              setNumberOfImage(0);
            } else {
              setNumberOfImage(numberOfImage + 1);
            }
          }}
        />
      </div>
      <div className="product-right">
        <h2 className="product-right-name">{product.name}</h2>
        <p className="product-right-price">
          {product.price}$
          <text className="product-right-price-old">
            {Math.round(product.price * (product.discount / 100 + 1))}$
          </text>
        </p>
        <p className="product-right-number">Количество: {product.number}шт.</p>
        <p className="product-right-description">{product.description}</p>
      </div>
    </div>
  );
};

Product.propTypes = {
  optionalObject: PropTypes.object,
  product: PropTypes.object,
};
