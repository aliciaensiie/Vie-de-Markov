######Makefile de la librairie############

INCLUDE=./SFML-2.5.1/include
LIB=./SFML-2.5.1/lib
PP=g++
LIBNAME=./lib/libcsfml-f.a

# fichiers objets cpp et fichiers d'archives de la lib correspondant.
OBJS_CPP = ./obj/Animation.o ./obj/Application.o ./obj/RenderObject.o ./obj/Label.o ./obj/Utility.o ./obj/ApplicationWrapper.o ./obj/AnimationWrapper.o ./obj/ViewWrapper.o ./obj/RenderObjectWrapper.o ./obj/LabelWrapper.o

lib: $(OBJS_CPP)
	ar rvs $(LIBNAME) $^



./obj/%.o: ./sfml_cpp/%.cpp
	$(PP) -g -c $< -I"$(INCLUDE)" -o $@


./obj/%.o: ./sfml_C/%.cpp
	$(PP) -g -c $< -I"$(INCLUDE)" -o $@




#"make doc" permet d'ouvrir la doc sous firefox (besoin de firefox, sinon ouvrer le fichier html via le naviguateur de votre choix)
.PHONY: doc
doc:
	firefox doc/html/index.html &


#"make clean" supprime uniquement les fichiers objets de la librairie
clean:
	rm -f $(OBJS_C) $(OBJS_CPP)

#"make clean_all" permettant de supprimer les fichers objets et les fichier d'archives '.a' de la librairie

clean_all :
	rm -f $(OBJS_C) $(OBJS_CPP) $(LIBNAME)