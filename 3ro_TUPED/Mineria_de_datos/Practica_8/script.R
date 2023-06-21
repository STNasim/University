library(pacman)
p_load(arules,arulesCBA,arulesViz,caret,arulesSequences)
rm(list = ls())
gc()

#1
data(zaki)

#a
print(zaki)
summary(zaki)
inspect(zaki)

#b
seq1 <- cspade(zaki,
              parameter =list(support = 0.1),
              control = list(verbose=F))
summary(seq1)
inspect(seq1)

seq25 <- cspade(zaki,
               parameter =list(support = 0.25),
               control = list(verbose=F))
summary(seq25)
inspect(seq25)

seq4 <- cspade(zaki,
               parameter =list(support = 0.4),
               control = list(verbose=F))
summary(seq4)
inspect(seq4)

seq7 <- cspade(zaki,
               parameter = list(support = 0.7),
               control = list(verbose=F))
summary(seq7)
inspect(seq7)

#c

#summary(seq4)
seq4_1 <- seq4[size(seq4,"items")==1]
inspect(seq4_1)

seq4_2 <- seq4[size(seq4,"items")>1]
inspect(seq4_2)

seq4 <- sort(seq4, by = "support", decreasing = TRUE)
inspect(seq4)

#2
rm(list = ls())
gc()

transacciones <- read_baskets(con = "sequences.txt",
                              info = c("sequenceID","eventID","SIZE"))
summary(transacciones)

seq <- cspade(transacciones,
               parameter = list(support = 0.002),
               control = list(verbose=F))
summary(seq)
inspect(sort(seq, by = "support", decreasing = TRUE)[1:10])

seq_2 <- seq[size(seq,"items")>1]
inspect(seq_2)

