# Convert reason files to ocaml files
# TODO probably should use a for loop

FILES="utils setup bucklescript rebel npmDep native"

for file in $FILES
do
  rm -f src/$file.ml && refmt -print ml -parse re src/$file.re >> src/$file.ml
done

PROJECT=$1


# recompile oasis just in case _oasis is changed
oasis setup && ./configure && make
cp -f ./rebel.native $PROJECT/node_modules/.bin/rebel && \
cd $PROJECT && npm start