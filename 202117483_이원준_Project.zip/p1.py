# 프로젝트 문제 1번

# 다섯 개의 자연수를 입력받아 리스트에 저장
numbers = [int(input()) for _ in range(5)]

# 평균 계산 (합을 개수로 나눔)
average = sum(numbers) // 5

# 중앙값 계산 (정렬 후 가운데 값)
numbers.sort()
median = numbers[2]

# 결과 출력
print(average)
print(median)
