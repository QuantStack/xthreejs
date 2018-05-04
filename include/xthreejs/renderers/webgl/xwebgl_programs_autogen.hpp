#ifndef XTHREE_WEBGL_PROGRAMS_HPP
#define XTHREE_WEBGL_PROGRAMS_HPP

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
    // webgl_programs declaration
    //

    template<class D>
    class xwebgl_programs : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xwebgl_programs();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using webgl_programs = xw::xmaterialize<xwebgl_programs>;

    using webgl_programs_generator = xw::xgenerator<xwebgl_programs>;

    //
    // webgl_programs implementation
    //


    template <class D>
    inline void xwebgl_programs<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xwebgl_programs<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xwebgl_programs<D>::xwebgl_programs()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xwebgl_programs<D>::set_defaults()
    {
        this->_model_name() = "WebGLProgramsModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xwebgl_programs>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_programs>>;
    extern template class xw::xgenerator<xthree::xwebgl_programs>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xwebgl_programs>>;
#endif

#endif