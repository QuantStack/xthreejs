#ifndef XTHREE_WEBGL_RENDER_TARGET_CUBE_HPP
#define XTHREE_WEBGL_RENDER_TARGET_CUBE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // webgl_render_target_cube declaration
    //

    template<class D>
    class xwebgl_render_target_cube : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xwebgl_render_target_cube();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using webgl_render_target_cube = xw::xmaterialize<xwebgl_render_target_cube>;

    using webgl_render_target_cube_generator = xw::xgenerator<xwebgl_render_target_cube>;

    //
    // webgl_render_target_cube implementation
    //


    template <class D>
    inline void xwebgl_render_target_cube<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xwebgl_render_target_cube<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xwebgl_render_target_cube<D>::xwebgl_render_target_cube()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xwebgl_render_target_cube<D>::set_defaults()
    {
        this->_model_name() = "WebGLRenderTargetCubeModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xwebgl_render_target_cube));
//}
#endif