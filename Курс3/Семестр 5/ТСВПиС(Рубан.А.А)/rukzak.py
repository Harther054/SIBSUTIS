def backpack(vls, wghts, cpcty):
  n = len(wghts)
  maxValues = [0] * (cpcty + 1)

  for w in range(cpcty + 1):
      for i in range(n):
          if wghts[i] <= w:
              maxValues[w] = max(maxValues[w], maxValues[w - wghts[i]] + vls[i])
              print(f"рассчитано максимальное значение при весе {w} = {w} - {wghts[i]} + {vls[i]} = {maxValues[w - wghts[i]]} + {vls[i]} = {maxValues[w - wghts[i]] + vls[i]}")
  return maxValues[cpcty]

cpcty = 20
wghts = [3, 5, 8]
vls = [8, 14, 23]
maxValue = backpack(vls, wghts, cpcty)
print("Максимальная ценность:", maxValue)