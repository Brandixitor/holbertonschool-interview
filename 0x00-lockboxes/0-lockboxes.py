#!/usr/bin/python3


def canUnlockAll(boxes):
    """ Unlocks all boxes """
    visited = [False for v in range(len(boxes))]
    visited[0] = True
    stack = boxes[0]

    while(len(stack)):
        element = stack[-1]
        stack.pop()
        try:
            if not visited[element]:
                visited[element] = True
            for node in boxes[element]:
                if not visited[node]:
                    stack.append(node)
        except:
            pass
    return all(visited)
