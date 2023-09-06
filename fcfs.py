def fcfs(arrival_time, burst_time, number_of_processes):

  completion_times = []
  current_time = 0
  for i in range(number_of_processes):
    if arrival_time[i] <= current_time:
      current_time += burst_time[i]
      completion_times.append(current_time)
    else:
      current_time = arrival_time[i] + burst_time[i]
      completion_times.append(current_time)

  turn_around_times = []
  waiting_times = []
  for i in range(number_of_processes):
    turn_around_times.append(completion_times[i] - arrival_time[i])
    if i == 0:
      waiting_times.append(0)
    else:
      waiting_times.append(turn_around_times[i] - burst_time[i])
      
  turn_time=sum(turn_around_times)
  average_turn_around_time = turn_time/number_of_processes
  average_waiting_time = sum(waiting_times) / number_of_processes

  return completion_times, turn_around_times, waiting_times, average_waiting_time,average_turn_around_time


if __name__ == "__main__":
  arrival_time = [0, 4, 1]
  burst_time = [3, 3, 3]
  number_of_processes = 3

  completion_times, turn_around_times, waiting_times, average_waiting_time, average_turn_around_time = fcfs(arrival_time, burst_time, number_of_processes)
  print("Completion times:", completion_times)
  print("Turn around times:", turn_around_times)
  print("Waiting times:", waiting_times)
  print("Average waiting time:", average_waiting_time)
  print("Average turn around time:", average_turn_around_time)
