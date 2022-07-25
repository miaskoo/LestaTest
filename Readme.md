Для сборки проекта нужно использовать mvs17 или mvs19.
Создал отдельные классы для частиц(Particle), эмиттеров(Emitter) и пула эмиттеров(PoolEmitters) для взаимодействия с частицами.
Вся обработка движения частиц происходит в классе Physics а их отрисовка в Render.
Все переменные которые можно менять находятся в variablesForTest.

Подумал лучшим решением данной задачи будет создать кэш из двух кадров, и
кэшировать туда информацию которая нужна только для Render. Так я могу
гарантировать, что у Render всегда будет что отрисовать, даже если Physics не
будет поспевать обработать все частицы.
В свою очередь Physics не будет создавать новых кадров до тех пор, пока Render
не начнет отрисовку уже нового кадра.