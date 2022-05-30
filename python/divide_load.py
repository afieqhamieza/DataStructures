import sys

def solution(A):
  """Your solution goes here."""
  sys.stderr.write('Tip: Use sys.stderr.write() to write debug messages on the output tab.\n')
  
  lenA = len(A)
  # generate prrefix sum
  prefSum = [0]*lenA
  prefSum[0] = A[0]

  for i in range(1, lenA):
      prefSum[i] = prefSum[i-1] + A[i]

  # generate suffix sum
  sufSum = [0]*lenA
  sufSum[lenA-1] = A[lenA-1]

  for i in range(lenA-2, -1, -1):
      sufSum[i] = sufSum[i+1] + A[i]

  # init min diff
  diff = sys.maxsize

  #travers and calculaate min sum
  for i in range(lenA-1):
      diffTemp = abs(prefSum[i] - sufSum[i+1])

      diff = min(diff, diffTemp)
  
  return diff


def main():
  """Read from stdin, solve the problem, write answer to stdout."""
#   input = sys.stdin.readline().split()
  A = [7,9,5,10]
  sys.stdout.write(str(solution(A)))


if __name__ == "__main__":
  main()
