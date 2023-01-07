Simulator for managing driver career in motorsport GPs.

You can run app in docker (Dockerfile provided):
1. Build container at first:
   docker build . -t grand-prix-manager:0.1.0
2. Run app inside container then:
   docker run --rm --interactive --tty grand-prix-manager:0.1.0
