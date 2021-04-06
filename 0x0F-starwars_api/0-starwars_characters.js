#!/usr/bin/node

const req = require('request');
const id = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${id}/`;

/* console.log(url); */
req(url, (err, res, body) => {
  if (err) throw err;
  for (const charUrl of JSON.parse(body).characters) {
    req(charUrl, (err, res, body) => {
      if (err) throw err;
      console.log(JSON.parse(body).name);
    });
  }
});
