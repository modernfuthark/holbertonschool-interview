#!/usr/bin/node

const req = require('request');
const id = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${id}/`;

req(url, async (err, res, body) => {
  if (err) throw err;
  for (const cUrl of JSON.parse(body).characters) {
    await new Promise((resolve, reject) => {
      req(cUrl, (err, res, body) => {
        if (err) {
          reject(err);
        } else {
          /* console.log(cUrl) */
          console.log(JSON.parse(body).name);
          resolve();
        }
      });
    });
  }
});
