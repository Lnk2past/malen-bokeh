#include "malen/malen.h"
#include <string>

namespace malen
{
class Bokeh : public Malen
{
public:
    template <typename... KW>
    PyObject* make_new_figure(const std::string &title, KW... kw)
    {
        return invoke("malen.bokeh", __FUNCTION__, args(title), kwargs(kw...));
    }

    template <template<typename...> class C1, template<typename...> class C2, typename T1, typename T2, typename... KW>
    PyObject* plot(PyObject* figure, const std::string &plot_type, const C1<T1> &datax, const C2<T2> &datay, KW... kw)
    {
        return invoke("malen.bokeh", __FUNCTION__, args(figure, plot_type, datax, datay), kwargs(kw...));
    }

    template <template<typename...> class C, typename T, typename... KW>
    PyObject* image(PyObject* figure, const C<C<T>> &image, KW... kw)
    {
        return invoke("malen.bokeh", __FUNCTION__, args(figure, image), kwargs(kw...));
    }

    template <typename... KW>
    PyObject* slider(PyObject* renderer, const std::string &title, const std::size_t start, const std::size_t end, KW... kw)
    {
        return invoke("malen.bokeh", __FUNCTION__, args(renderer, title, start, end), kwargs(kw...));
    }

    template <typename... KW>
    PyObject* image_slider(PyObject* renderer, const std::string &title, const std::size_t start, const std::size_t end, KW... kw)
    {
        return invoke("malen.bokeh", __FUNCTION__, args(renderer, title, start, end), kwargs(kw...));
    }

    template <typename... KW>
    PyObject* ticker(const std::string &ticker_type, KW... kw)
    {
        return invoke("malen.bokeh", __FUNCTION__, args(ticker_type), kwargs(kw...));
    }

    template <typename... KW>
    PyObject* color_mapper(const std::string &mapper_type, KW... kw)
    {
        return invoke("malen.bokeh", __FUNCTION__, args(mapper_type), kwargs(kw...));
    }

    template <typename... KW>
    PyObject* color_bar(PyObject *figure, KW... kw)
    {
        return invoke("malen.bokeh", __FUNCTION__, args(figure), kwargs(kw...));
    }

    PyObject* layout(PyObject* obj1, PyObject *obj2)
    {
        return invoke("malen.bokeh", __FUNCTION__, args(obj1, obj2));
    }

    template <typename... KW>
    void generate_html(PyObject *figure, const std::string &filename, KW... kw)
    {
        invoke("malen.bokeh", __FUNCTION__, args(figure, filename), kwargs(kw...));
    }
};
}
