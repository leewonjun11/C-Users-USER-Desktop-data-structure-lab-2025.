# 프로젝트 문제 2번
input = "))()"

def problem2(input):
    balance = 0
    left_needed = 0
    
    # 문자열을 왼쪽부터 스캔
    for char in input:
        if char == '(':
            balance += 1
        elif char == ')':
            balance -= 1
            
        # 균형이 음수가 되면 앞에 '('를 추가해야 함
        if balance < 0:
            left_needed += abs(balance)  # 음수만큼 앞에 '(' 추가 필요
            balance = 0  # 균형 초기화
    
    # 스캔 완료 후 남은 양수 균형은 뒤에 ')' 추가 필요
    right_needed = balance
    
    # 총 필요한 괄호 개수
    result = left_needed + right_needed
    return result

result = problem2(input)

print(result)
