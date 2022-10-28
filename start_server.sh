#!/usr/bin/bash

echo "starting python server"
#python3 src/api/api.py
flask --app src/app/app.py --debug run --host=10.0.20.61 --port=5000

