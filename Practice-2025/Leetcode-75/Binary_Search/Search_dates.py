from datetime import datetime

def binary_search_dates(sorted_list_of_dates, target_date_str, date_format='%Y-%m-%d'):
  """
  Performs a binary search on a sorted list of date strings to find the
  index of the first date that is greater than or equal to the target date.

  Args:
    sorted_list_of_dates: A sorted list of date strings.
    target_date_str: The target date as a string.
    date_format: The format of the date strings. Defaults to '%Y-%m-%d'.

  Returns:
    The index of the first date in the list that is greater than or equal to
    the target date, or the length of the list if no such date exists.
    Returns -1 if the list is empty or an error occurs.
  """
  if not sorted_list_of_dates:
    return -1

  try:
    target_date = datetime.strptime(target_date_str, date_format)
  except ValueError:
    print(f"Error: Invalid date format for target_date_str. Please use '{date_format}'.")
    return -1

  low = 0
  high = len(sorted_list_of_dates)

  while low < high:
    mid = low + (high - low) // 2
    try:
      mid_date = datetime.strptime(sorted_list_of_dates[mid], date_format)
      if mid_date == target_date:
        return mid
      elif mid_date < target_date:
        low = mid + 1
      else:
        high = mid
    except ValueError:
      print(f"Warning: Skipping invalid date string '{sorted_list_of_dates[mid]}'.")
      # Handle the error, maybe remove the invalid date and retry, or adjust bounds
      # For simplicity, we'll just increment low to move past it in this example
      low = mid + 1

  return low - 1

def find_dates_less_than_or_equal_binary(sorted_list_of_dates, given_date_str, date_format='%Y-%m-%d'):
  """
  Finds all dates in a sorted list that are less than or equal to a given date
  using binary search to optimize the process.

  Args:
    sorted_list_of_dates: A sorted list of date strings.
    given_date_str: The given date as a string.
    date_format: The format of the date strings. Defaults to '%Y-%m-%d'.

  Returns:
    A new list containing dates from the input list that are less than or
    equal to the given date, as datetime objects.
  """
  try:
    given_date = datetime.strptime(given_date_str, date_format)
  except ValueError:
    print(f"Error: Invalid date format for given_date_str. Please use '{date_format}'.")
    return []

  first_greater_index = binary_search_dates(sorted_list_of_dates, given_date_str, date_format)
  print(sorted_list_of_dates[first_greater_index])
  result = []
  for i in range(first_greater_index + 1):
    try:
      current_date = datetime.strptime(sorted_list_of_dates[i], date_format)
      result.append(current_date)
    except ValueError:
      print(f"Warning: Skipping invalid date string '{sorted_list_of_dates[i]}'.")

  return result

# Example Usage:
dates = ["2025-03-15", "2025-03-25", "2025-03-31", "2025-04-01", "2025-04-05"]
given_date_str = "2025-03-31"
date_format = "%Y-%m-%d"

# Ensure the list is sorted
dates.sort()

matching_dates_binary = find_dates_less_than_or_equal_binary(dates, given_date_str, date_format)

print(f"Given date: {given_date_str}")
print("Dates less than or equal to the given date (using binary search):")
for date_obj in matching_dates_binary:
  print(date_obj.strftime(date_format))