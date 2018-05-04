#ifndef XTHREE_WEBGL_EXTENSIONS_HPP
#define XTHREE_WEBGL_EXTENSIONS_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"

namespace xthree
{
    //
    // webgl_extensions declaration
    //

    template<class D>
    class xwebgl_extensions : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xwebgl_extensions();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using webgl_extensions = xw::xmaterialize<xwebgl_extensions>;

    using webgl_extensions_generator = xw::xgenerator<xwebgl_extensions>;

    //
    // webgl_extensions implementation
    //


    template <class D>
    inline void xwebgl_extensions<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xwebgl_extensions<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xwebgl_extensions<D>::xwebgl_extensions()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xwebgl_extensions<D>::set_defaults()
    {
        this->_model_name() = "WebGLExtensionsModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xwebgl_extensions));
//}
#endif