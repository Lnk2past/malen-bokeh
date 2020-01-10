#include "malen/malen.h"
#include <string>

namespace mb
{
class MalenBokeh : public malen::Malen
{
public:
    MalenBokeh():
        malen::Malen({".", "..", "../.."})
    {}

    template <typename... KW>
    PyObject* make_new_figure(const std::string &title, KW... kw)
    {
        return invoke("malenbokeh", __FUNCTION__, malen::args(title), malen::kwargs(kw...));
    }

    template <template<typename...> class C1, template<typename...> class C2, typename T1, typename T2, typename... KW>
    PyObject* plot(PyObject* figure, const std::string &plot_type, const C1<T1> &datax, const C2<T2> &datay, KW... kw)
    {
        return invoke("malenbokeh", __FUNCTION__, malen::args(figure, plot_type, datax, datay), malen::kwargs(kw...));
    }

    template <template<typename...> class C, typename T, typename... KW>
    PyObject* image(PyObject* figure, const C<C<T>> &image, KW... kw)
    {
        return invoke("malenbokeh", __FUNCTION__, malen::args(figure, image), malen::kwargs(kw...));
    }

    template <typename... KW>
    PyObject* slider(PyObject* renderer, const std::string &title, const std::size_t start, const std::size_t end, KW... kw)
    {
        return invoke("malenbokeh", __FUNCTION__, malen::args(renderer, title, start, end), malen::kwargs(kw...));
    }

    template <typename... KW>
    PyObject* ticker(const std::string &ticker_type, KW... kw)
    {
        return invoke("malenbokeh", __FUNCTION__, malen::args(ticker_type), malen::kwargs(kw...));
    }

    template <typename... KW>
    PyObject* color_mapper(const std::string &mapper_type, KW... kw)
    {
        return invoke("malenbokeh", __FUNCTION__, malen::args(mapper_type), malen::kwargs(kw...));
    }

    template <typename... KW>
    void color_bar(PyObject *figure, KW... kw)
    {
        return invoke("malenbokeh", __FUNCTION__, malen::args(figure), malen::kwargs(kw...));
    }

    PyObject* layout(PyObject* obj1, PyObject *obj2)
    {
        return invoke("malenbokeh", __FUNCTION__, malen::args(obj1, obj2));
    }

    template <typename... KW>
    void generate_html(PyObject *figure, const std::string &filename, KW... kw)
    {
        invoke("malenbokeh", __FUNCTION__, malen::args(figure, filename), malen::kwargs(kw...));
    }
};
}
