create table logs(
    id integer primary key autoincrement,
    first_number real,
    operand text,
    second_number real,
    result real,
    time text
);

insert into logs(first_number, operand, second_number, result, time)
values(12,'+',34, 46, 'sat 19 nov 1:23PM 2025');