#include <vector>
#include <map>

class TeamTasks {
public:
	// ѕолучить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const string& person) const
	{
		if (tasksPersons.count(person) > 0)
			return tasksPersons.at(person);

		return { {TaskStatus::NEW, 0}, {TaskStatus::IN_PROGRESS, 0}, {TaskStatus::TESTING, 0}, {TaskStatus::DONE, 0} };
	}

	// ƒобавить новую задачу (в статусе NEW) дл€ конкретного разработчитка
	void AddNewTask(const string& person)
	{
		++tasksPersons[person][TaskStatus::NEW];
	}

	// ќбновить статусы по данному количеству задач конкретного разработчика,
	// подробности см. ниже
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count)
	{
		TasksInfo updated_tasks, untouched_tasks;
		int sNew, sInProgress, sTesting, sDone;

		TasksInfo tasks = GetPersonTasksInfo(person);
		if (tasks.size() == 0)
			return { updated_tasks, untouched_tasks };

		try
		{
			sNew = tasks.at(TaskStatus::NEW);
		}
		catch (...)
		{
			sNew = 0;
		}
		try
		{
			sInProgress = tasks.at(TaskStatus::IN_PROGRESS);
		}
		catch (...)
		{
			sInProgress = 0;
		}
		try
		{
			sTesting = tasks.at(TaskStatus::TESTING);
		}
		catch (...)
		{
			sTesting = 0;
		}
		try
		{
			sDone = tasks.at(TaskStatus::DONE);
		}
		catch (...)
		{
			sDone = 0;
		}

		if (sNew >= task_count)
		{
			tasksPersons[person][TaskStatus::NEW] = sNew - task_count;
			tasksPersons[person][TaskStatus::IN_PROGRESS] += task_count;
			updated_tasks[TaskStatus::IN_PROGRESS] = task_count;
			if (sNew - task_count != 0) untouched_tasks[TaskStatus::NEW] = sNew - task_count;
			if (tasksPersons[person][TaskStatus::TESTING] != 0) untouched_tasks[TaskStatus::TESTING] = tasksPersons[person][TaskStatus::TESTING];
		}
		else
		{
			tasksPersons[person].erase(TaskStatus::NEW);
			int delta = task_count - sNew;
			tasksPersons[person][TaskStatus::IN_PROGRESS] += sNew;
			if (sNew != 0) updated_tasks[TaskStatus::IN_PROGRESS] = sNew;
			if (sInProgress >= delta)
			{
				tasksPersons[person][TaskStatus::IN_PROGRESS] -= delta;
				tasksPersons[person][TaskStatus::TESTING] += delta;
				updated_tasks[TaskStatus::TESTING] = delta;
				if (sInProgress - delta != 0) untouched_tasks[TaskStatus::IN_PROGRESS] = delta;
				if (sTesting != 0) untouched_tasks[TaskStatus::TESTING] = sTesting;
			}
			else
			{
				if (tasksPersons[person][TaskStatus::IN_PROGRESS] - sInProgress <= 0) tasksPersons[person].erase(TaskStatus::IN_PROGRESS);
				delta -= sInProgress;
				if (sTesting + sInProgress - delta < 0)
					delta = sTesting;

				tasksPersons[person][TaskStatus::TESTING] = sTesting + sInProgress - delta;
				tasksPersons[person][TaskStatus::DONE] += delta;
				if (sInProgress != 0) updated_tasks[TaskStatus::TESTING] = sInProgress;
				if (sTesting - delta == 0) tasksPersons[person].erase(TaskStatus::TESTING);
				if (delta != 0) updated_tasks[TaskStatus::DONE] = delta;
				if (sTesting - delta != 0) untouched_tasks[TaskStatus::TESTING] = sTesting - delta;
			}
		}

		return { updated_tasks, untouched_tasks };
	}

private:
	map<string, TasksInfo> tasksPersons;
};