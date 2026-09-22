class Solution:
  def canCompleteCircuit(self, gas: list[int], cost: list[int]) -> int:
    ans = 0
    net = 0
    summ = 0

    # Try to start from each index.
    for i in range(len(gas)):
      net += gas[i] - cost[i]
      summ += gas[i] - cost[i]
      if summ < 0:
      
