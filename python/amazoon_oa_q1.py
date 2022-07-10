from collections import deque 

def chooseFleets(wheels):
    # Write your code here
    result = []

    for wheel in wheels:
        res = 0
        
        if wheel%2 != 0:
            result.append(res)
            continue
        
        wheelResult = []
        q = deque([])
        
        for i in range(wheel, 0, -1):
            res += 1
            q.append(2)
            i-=2
                
        wheelResult.append(q)
        
        for i in range(len(q)):
            if i<=(len(q)-2):
                if q[i] == 2 and q[i+1] == 2:
                    q[i] = 4
                    del q[i+1]  

        wheelResult.append(q)
        result.append(res)
        print(result)
                    
        
    return result

if __name__ == '__main__':
    print(chooseFleets([4,3,2,6]))