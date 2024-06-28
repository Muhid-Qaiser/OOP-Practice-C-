#include <iostream>
#include <string>
using namespace std;

class Genre
{
    string name;

public:
    Genre(string name) : name(name) {}

    string getName() const
    {
        return name;
    }
};

class Director
{
    string name;

public:
    Director(string name) : name(name) {}

    string getName() const
    {
        return name;
    }
};

class Actor
{
    string name;

public:
    Actor(string name) : name(name) {}

    string getName() const
    {
        return name;
    }
};

class Movie
{
    string title;
    Director *director;
    Genre **genres;
    Actor **actors;
    int numGenres;
    int numActors;
    int maxGenres;
    int maxActors;

public:
    Movie(string title, Director *director, int maxGenres, int maxActors)
        : title(title), director(director), maxGenres(maxGenres), maxActors(maxActors)
    {
        numGenres = 0;
        numActors = 0;
        genres = new Genre *[maxGenres];
        actors = new Actor *[maxActors];
    }

    ~Movie()
    {
        delete[] genres;
        delete[] actors;
    }

    void addGenre(Genre *genre)
    {
        if (numGenres < maxGenres)
        {
            genres[numGenres] = genre;
            numGenres++;
        }
    }

    void addActor(Actor *actor)
    {
        if (numActors < maxActors)
        {
            actors[numActors] = actor;
            numActors++;
        }
    }

    string getTitle() const
    {
        return title;
    }

    Director *getDirector() const
    {
        return director;
    }

    Genre **getGenres() const
    {
        return genres;
    }

    int getNumGenres() const
    {
        return numGenres;
    }

    Actor **getActors() const
    {
        return actors;
    }

    int getNumActors() const
    {
        return numActors;
    }
};

class MovieDatabase
{
    Movie **movies;
    int numMovies;
    int maxMovies;
    Director **directors;
    int numDirectors;
    int maxDirectors;
    Actor **actors;
    int numActors;
    int maxActors;

public:
    MovieDatabase(int maxMovies, int maxDirectors, int maxActors)
        : maxMovies(maxMovies), maxDirectors(maxDirectors), maxActors(maxActors)
    {
        numMovies = 0;
        numDirectors = 0;
        numActors = 0;
        movies = new Movie *[maxMovies];
        directors = new Director *[maxDirectors];
        actors = new Actor *[maxActors];
    }

    ~MovieDatabase()
    {
        delete[] movies;
        delete[] directors;
        delete[] actors;
    }

    void addMovie(Movie *movie)
    {
        if (numMovies < maxMovies)
        {
            movies[numMovies] = movie;
            numMovies++;
        }
    }

    void addDirector(Director *director)
    {
        if (numDirectors < maxDirectors)
        {
            directors[numDirectors] = director;
            numDirectors++;
        }
    }

    void addActor(Actor *actor)
    {
        if (numActors < maxActors)
        {
            actors[numActors] = actor;
            numActors++;
        }
    }

    Movie **getMovies() const
    {
        return movies;
    }

    int getNumMovies() const
    {
        return numMovies;
    }

    Director **getDirectors() const
    {
        return directors;
    }

    int getNumDirectors() const
    {
        return numDirectors;
    }

    Actor **getActors() const
    {
        return actors;
    }

    int getNumActors() const
    {
        return numActors;
    }
};

int main()
{
    // Create a movie database
    MovieDatabase *db = new MovieDatabase(10, 10, 10);

    // Add a director
    Director *director = new Director("Christopher Nolan");
    db->addDirector(director);

    // Add some actors
    Actor *actor1 = new Actor("Leonardo DiCaprio");
    db->addActor(actor1);
    Actor *actor2 = new Actor("Tom Hardy");
    db->addActor(actor2);

    // Create a movie and add it to the database
    Movie *movie = new Movie("Inception", director, 2, 2);
    movie->addGenre(new Genre("Action"));
    movie->addGenre(new Genre("Sci-Fi"));
    movie->addActor(actor1);
    movie->addActor(actor2);
    db->addMovie(movie);

    // Get all movies in the database and print their details
    Movie **movies = db->getMovies();
    int numMovies = db->getNumMovies();
    for (int i = 0; i < numMovies; i++)
    {
        Movie *movie = movies[i];

        cout << "Movie: " << movie->getTitle() << endl;
        cout << "Director: " << movie->getDirector()->getName() << endl;
        cout << "Genres:";
        Genre **genres = movie->getGenres();
        int numGenres = movie->getNumGenres();
        for (int j = 0; j < numGenres; j++)
        {
            Genre *genre = genres[j];
            cout << " " << genre->getName();
        }
        cout << endl;
        cout << "Actors:";
        Actor **actors = movie->getActors();
        int numActors = movie->getNumActors();
        for (int j = 0; j < numActors; j++)
        {
            Actor *actor = actors[j];
            cout << " " << actor->getName();
        }
        cout << endl;
    }

    // Clean up memory
    delete db;
    delete director;
    delete actor1;
    delete actor2;

    return 0;
}
