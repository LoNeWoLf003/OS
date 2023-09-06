def sjf(arrival_time, burst_time, number_of_processes):

  pq = []
  for i in range(number_of_processes):
    pq.append((arrival_time[i], burst_time[i], i))

  completion_times = []
  current_time = 0
  while len(pq) > 0:
    process = pq.pop(0)
    if arrival_time[process[2]] <= current_time:
      current_time += process[1]
      completion_times.append(current_time)
    else:
      current_time = arrival_time[process[2]] + process[1]
      completion_times.append(current_time)
    for i in range(len(pq)):
      if pq[i][1] > process[1]:
        pq[i], pq[0] = pq[0], pq[i]

  turn_around_times = []
  waiting_times = []
  for i in range(number_of_processes):
    turn_around_times.append(completion_times[i] - arrival_time[i])
    waiting_times.append(turn_around_times[i] - burst_time[i])

  average_waiting_time = sum(waiting_times) / number_of_processes
  average_turn_around_time = sum(turn_around_times) / number_of_processes

  return completion_times, turn_around_times, waiting_times, average_waiting_time, average_turn_around_time


if __name__ == "__main__":
  arrival_time = [0, 1, 2, 3]
  burst_time = [4, 5, 2, 1]
  number_of_processes = 4

  completion_times, turn_around_times, waiting_times, average_waiting_time,average_turn_around_time = sjf(arrival_time, burst_time, number_of_processes)
  print("Completion times:", completion_times)
  print("Turn around times:", turn_around_times)
  print("Waiting times:", waiting_times)
  print("Average waiting time:", average_waiting_time)
  print("Average turn around time:", average_turn_around_time)
