export ACT_HOME=$HOME/act-local
export PATH=$PATH:$ACT_HOME/bin

aflat -Tsky130l IM.act > IM.pr

actsim -Wlang_subst:off testmul.act test
