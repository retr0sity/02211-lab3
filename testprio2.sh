export ACT_HOME=$HOME/act-local
export PATH=$PATH:$ACT_HOME/bin
aflat -Tsky130l prio2.act > prio2.pr

actsim -Wlang_subst:off testprio2.act test