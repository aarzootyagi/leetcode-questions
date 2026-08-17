from collections import deque

class Solution:
    def validPath(self, n, edges, source, destination):
        g = [[] for _ in range(n)]

        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        q = deque([source])
        vis = [False] * n
        vis[source] = True

        while q:
            u = q.popleft()

            if u == destination:
                return True

            for v in g[u]:
                if not vis[v]:
                    vis[v] = True
                    q.append(v)

        return False
        