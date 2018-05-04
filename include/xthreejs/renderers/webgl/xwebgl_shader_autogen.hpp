#ifndef XTHREE_WEBGL_SHADER_HPP
#define XTHREE_WEBGL_SHADER_HPP

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
    // webgl_shader declaration
    //

    template<class D>
    class xwebgl_shader : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xwebgl_shader();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using webgl_shader = xw::xmaterialize<xwebgl_shader>;

    using webgl_shader_generator = xw::xgenerator<xwebgl_shader>;

    //
    // webgl_shader implementation
    //


    template <class D>
    inline void xwebgl_shader<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xwebgl_shader<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xwebgl_shader<D>::xwebgl_shader()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xwebgl_shader<D>::set_defaults()
    {
        this->_model_name() = "WebGLShaderModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xwebgl_shader));
//}
#endif