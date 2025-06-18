# 프로젝트 문제 3번
input = [[4, 3, 2, 1],
         [0, 0, 0, 0],
         [0, 0, 9, 0],
         [1, 2, 3, 4]]
N = 4

forest = []

def problem3(input):
    bear_size = 2
    honeycomb_count = 0
    time = 0
    bear_x, bear_y = 0, 0
    # 입력 힌트

    # forest 리스트를 input 리스트로 초기화
    forest = [row[:] for row in input]
    
    # 곰의 초기 위치 찾기
    for i in range(N):
        for j in range(N):
            if forest[i][j] == 9:
                bear_x, bear_y = i, j
                forest[i][j] = 0
    print("곰의 초기 위치 x : {0}, y : {1}".format(bear_x, bear_y))

    #여기에서부터 코드를 작성하세요.
    from collections import deque

    # BFS로 가장 가까운 먹을 수 있는 벌집 찾기
    def bfs(start_x, start_y, bear_size):
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # 상하좌우
        visited = [[False] * N for _ in range(N)]
        queue = deque([(start_x, start_y, 0)])  # (x, y, distance)
        visited[start_x][start_y] = True
        
        candidates = []  # 같은 거리에 있는 벌집들을 저장
        min_distance = float('inf')
        
        while queue:
            x, y, dist = queue.popleft()
            
            # 이미 더 먼 거리는 탐색하지 않음
            if dist > min_distance:
                break
                
            # 현재 위치에 먹을 수 있는 벌집이 있는지 확인
            if forest[x][y] != 0 and forest[x][y] < bear_size:
                if dist < min_distance:
                    min_distance = dist
                    candidates = [(x, y, dist)]
                elif dist == min_distance:
                    candidates.append((x, y, dist))
            
            # 인접한 칸들을 큐에 추가
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                
                if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny]:
                    # 곰보다 큰 벌집이 있는 곳은 지나갈 수 없음
                    if forest[nx][ny] == 0 or forest[nx][ny] <= bear_size:
                        visited[nx][ny] = True
                        queue.append((nx, ny, dist + 1))
        
        if not candidates:
            return None
        
        # 우선순위: 위쪽 -> 왼쪽
        candidates.sort(key=lambda x: (x[0], x[1]))
        return candidates[0]
    
    while True:
        # 가장 가까운 먹을 수 있는 벌집 찾기
        target = bfs(bear_x, bear_y, bear_size)
        
        if target is None:
            # 더 이상 먹을 수 있는 벌집이 없음
            break
        
        target_x, target_y, distance = target
        
        # 곰을 목표 위치로 이동
        bear_x, bear_y = target_x, target_y
        time += distance
        
        # 벌집을 먹고 곰의 크기 증가
        forest[target_x][target_y] = 0
        honeycomb_count += 1
        
        # 곰의 크기가 먹은 벌집 수와 같아지면 크기 증가
        if honeycomb_count == bear_size:
            bear_size += 1
            honeycomb_count = 0
    
    result = time
    return result

result = problem3(input)

print(result)
