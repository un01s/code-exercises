# Git Intro

## three areas

* working directory

* stage/index area

* commit history (head)

```
working-dir --add--> index/stage --commit--> history
stage --checkout--> working-dir
history --checkout--> working-dir
```

Every commit has a unqiue hash. Either HEAD or master branch is just a pointer to one of the commit in the history.

The status of ```work dir``` and ```stage``` can be checked through ```git status```. To check ```history```, use ```git log```.


