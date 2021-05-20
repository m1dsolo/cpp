create table character (
    id integer primary key autoincrement not null, 
    name text not null, 
    type int not null, 
    race int not null, 
    level int not null, 
    exp int not null, 
    max_exp int not null, 
    hp int not null, 
    max_hp int not null, 
    atk int not null, 
    def int not null, 
    spd int not null
);