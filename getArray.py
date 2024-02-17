# basic function to remove brackets from leetcode input
# and return string array as output which can then be used
# as input to construct tree/graph
def removeBracket(str):
	return str.replace('[', '{').replace(']', '}')